#include<iostream>
#include<string>
#include<algorithm>
#include <queue>
using namespace std;
int n, k;
bool mas[150][150];
//bool ams[150][150];
void nol ()
{
    for (int q=0; q<101; q++)
    {
        for (int w=0; w<101; w++)
        {
            mas[q][w]=false;
        }
    }
}
int ma=-1;
int manom;
void fun (int nom, int ot)
{
    if (ot>ma)
    {
        ma=ot;
        manom=nom;
    }
    for (int w=0; w<101; w++)
    {
        if (mas[nom][w])
        {
            mas[nom][w]=false;
            mas[w][nom]=false;
            fun (w, ot+1);
            mas[nom][w]=true;
            mas[w][nom]=true;
        }
    }
    return;
}
int main()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    cin >> n;
    int otvet=0;
    for (int q=0; q<n; q++)
    {
        nol();
        ma=-1;
        cin >> k;
        for (int w=0; w<k-1; w++)
        {
            int a, b;
            cin >> a >> b;
            mas[a][b]=true;
            mas[b][a]=true;
        }
        fun (1, 0);
        ma=-1;
        fun (manom, 0);
        otvet+=ma;
    }
    cout << otvet;
    return 0;

}