#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    bool check=false;
    int cnt=0;
    cout << 2 << endl;
    fflush(stdout);
    cin>>s;
    if (s=="yes") ++cnt;
        cout << 3 << endl;
    fflush(stdout);
    cin>>s;
    if (s=="yes") ++cnt;
        cout << 5 << endl;
    fflush(stdout);
    cin>>s;
    if (s=="yes") ++cnt;
        cout << 7 << endl;
    fflush(stdout);
    cin>>s;
    if (s=="yes") ++cnt;
        cout << 4 << endl;
    fflush(stdout);
    cin>>s;
    if (s=="yes") ++cnt;
        cout << 9 << endl;
    fflush(stdout);
    cin>>s;
    if (s=="yes") ++cnt;
        cout << 25 << endl;
    fflush(stdout);
    cin>>s;
    if (s=="yes") ++cnt;
        cout << 49 << endl;
    fflush(stdout);
    cin>>s;
    if (s=="yes") ++cnt;
     cout << 11 << endl;
    fflush(stdout);
    cin>>s;
    if (s=="yes") ++cnt;
         cout << 13 << endl;
    fflush(stdout);
    cin>>s;
    if (s=="yes") ++cnt;
         cout << 17 << endl;
    fflush(stdout);
    cin>>s;
    if (s=="yes") ++cnt;
         cout << 19 << endl;
    fflush(stdout);
    cin>>s;
    if (s=="yes") ++cnt;
         cout << 23 << endl;
    fflush(stdout);
    cin>>s;
    if (s=="yes") ++cnt;
         cout << 29 << endl;
    fflush(stdout);
    cin>>s;
    if (s=="yes") ++cnt;
         cout << 31 << endl;
    fflush(stdout);
    cin>>s;
    if (s=="yes") ++cnt;
         cout << 37 << endl;
    fflush(stdout);
    cin>>s;
    if (s=="yes") ++cnt;
         cout << 41 << endl;
    fflush(stdout);
    cin>>s;
    if (s=="yes") ++cnt;
         cout << 43 << endl;
    fflush(stdout);
    cin>>s;
    if (s=="yes") ++cnt;
         cout << 47 << endl;
    fflush(stdout);
    cin>>s;
    if (s=="yes") ++cnt;
    if (cnt>=2)
    {
        cout << " composite" << endl;
        fflush(stdout);
    } else 
    {
        cout << "prime" << endl;
        fflush(stdout);
    }
    return 0;
}