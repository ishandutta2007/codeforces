#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=300+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;

vector<int>ans[maxn];
int arr[maxn];

bool f(string a)
{
    int arr[110];
    arr[0]=1;
    for(int i=1;i<a.length();i++)
    {
        if(a[i]==a[i-1])arr[i]=arr[i-1]+1;
        else arr[i]=1;
        if(arr[i]==7)return true;
    }
    return false;
}

int main()
{
    //freopen("in.txt","r",stdin);
    string str;
    cin>>str;
    if(f(str))cout<<"YES";
    else cout<<"NO";
    return 0;
}