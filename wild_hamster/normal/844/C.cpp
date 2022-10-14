#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void GetData(vector <pair<int, int> > &Data, const int N);
void Find_SubSequences(vector <pair<int, int> > &Data, const int N);
void GetArray(vector <int> &Array, vector <pair<int, int> > &Data, const int N);
void Next_Step(vector <int> &Array, vector <int> &Answer, int &SizeAnswer, int &ind,
               vector <int> &Taken, const int N, int &first_free);

void OutAnswer(vector <int> &Answer, const int SizeAnswer);

int main()
{
    int N = 0;
    cin >> N;

    vector <pair<int, int> > Data(N);
    GetData(Data, N);

    Find_SubSequences(Data, N);

    return 0;
}

void GetData(vector <pair<int, int> > &Data, const int N)
{
    for (size_t i = 0; i < N; i++)
    {
        cin >> Data[i].first;
        Data[i].second = i;
    }
    sort(Data.begin(), Data.end());
}

void Find_SubSequences(vector <pair<int, int> > &Data, const int N)
{
    vector <int> Array(N);
    GetArray(Array, Data, N);

    vector<int> Answer[N];
    vector <int> tempAnswer, Taken(N);
    int tempSizeAnswer = 0, NumbTaken = 0, SizeAnswer = 0, first_free = 0;

    while (NumbTaken != N)
    {
        int ind = first_free;
        int first_ind = ind;

        Next_Step(Array, tempAnswer, tempSizeAnswer, ind, Taken, N, first_free);
        while (ind != first_ind) Next_Step(Array, tempAnswer, tempSizeAnswer, ind,
                                           Taken, N, first_free);
        Answer[SizeAnswer] = tempAnswer;
        SizeAnswer++;
        NumbTaken += tempSizeAnswer;

        tempAnswer.clear();
        tempSizeAnswer = 0;
    }

    cout << SizeAnswer << "\n";
    for (size_t i = 0; i < SizeAnswer; i++) OutAnswer(Answer[i], Answer[i].size());
}

void GetArray(vector <int> &Array, vector <pair<int, int> > &Data, const int N)
{
    for (size_t i = 0; i < N; i++)
    {
        int ind = Data[i].second;
        Array[ind] = i;
    }
}

void Next_Step(vector <int> &Array, vector <int> &Answer, int &SizeAnswer, int &ind,
               vector <int> &Taken, const int N, int &first_free)
{
    Answer.push_back(Array[ind]);
    SizeAnswer++;

    Taken[ind] = 1;
    if (ind == first_free)
    {
        first_free++;
        while (first_free < N && Taken[first_free] != 0) first_free++;
    }

    ind = Answer[SizeAnswer - 1];
}

void OutAnswer(vector <int> &Answer, const int SizeAnswer)
{
    cout << SizeAnswer << " ";
    for (size_t i = 0; i < SizeAnswer; i++) cout << Answer[i] + 1 << " ";
    cout << "\n";
}