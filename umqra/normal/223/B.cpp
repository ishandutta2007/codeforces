#include <iostream>
#include <vector>
#include <string>
using namespace std;    
const int N = 400000;      


vector <int> pos[30];    
int seg[N];
bool letter[30];  

int border[30];

void fail()
{
    cout << "No";
    exit(0);
}

int bp(char a, int rb)
{
    int ind = a - 'a';
    int l = 0, r = (int)pos[a - 'a'].size() - 1;     
    while (l <= r)
    {                  
        if (l + 1 >= r)
        {
            if (pos[ind][r] < rb)
                return r;
            if (pos[ind][l] < rb)
                return l;
            return -1;
        }
        int m = (l + r) / 2;
        if (pos[ind][m] >= rb)
            r = m;
        else
            l = m;
    }
    return -1;
}

int bp2(char a, int rb)
{
    int ind = a - 'a';
    int l = 0, r = (int)pos[ind].size() - 1;
    while (l <= r)
    {                  
        if (l + 1 >= r)
        {
            if (pos[ind][l] > rb)
                return l;
            if (pos[ind][r] > rb)
                return r;
            return -1;
        }
        int m = (l + r) / 2;
        if (pos[ind][m] <= rb)
            l = m;
        else
            r = m;
    }
    return -1;

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);  
    freopen ("output.txt", "w", stdout);
#endif
    string s, t;
    cin >> s >> t;  

    for (int i = 0; i < (int)s.length(); i++)
        letter[s[i] - 'a'] = 1;
    for (int i = 0; i < (int)t.length(); i++)
        if (!letter[t[i] - 'a'])
            fail();


    for (int i = 0; i < (int)s.length(); i++)
        pos[s[i] - 'a'].push_back(i);                  
    seg[(int)t.length() - 1] = (int)pos[t[(int)t.length() - 1] - 'a'].size() - 1;

    for (int i = (int)t.length() - 2; i >= 0; i--)
    {                                              
        int num = bp(t[i], pos[t[i + 1] - 'a'][seg[i + 1]]);      
        if (num == -1)
            fail();
        seg[i] = num;
    }
    for (int i = 0; i < 30; i++)
        border[i] = -1;
    border[t[0] - 'a'] = seg[0];
    int l = pos[t[0] - 'a'][0]; 

    for (int i = 1; i < (int)t.length(); i++)
    {                                       
        int b = bp2(t[i], l);
        if (b == -1)
            fail();
        if (border[t[i] - 'a'] + 1 < b)
            fail();
        border[t[i] - 'a'] = max(seg[i], border[t[i] - 'a']);;
        l = pos[t[i] - 'a'][b];
    }                          
    for (int i = 0; i < 30; i++)
        if (border[i] != (int)pos[i].size() - 1)
            fail();
    cout << "Yes";
    return 0;
}