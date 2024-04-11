#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define pb push_back
#define clr(i) memset(i,0,sizeof(i))

typedef pair<int,int> pii;
typedef long long ll;

int a[2005];
int main()
{
    a[1] = -1;
    int S = -2;
    int k;
    cin>>k;
    k--;
    int i;
    for(i=2;;++i)
    {
        if(k+1-S<=1000000) {a[i]=k+1-S;break;}
        else a[i]=1000000,S+=999999;
    }
    cout << i << endl;
    for(int j=1;j<=i;++j)cout<<a[j]<<" ";
}