#include<iostream>
#include<stdio.h>
using namespace std;
int p[1005];
int main()
{
    int n;
	cin>>n;
    p[0]=1;
    int ans = 1;
    int tmp = 0;
    for(int i=0;i<n;i++){
        tmp=(tmp+i)%n;
        if(p[tmp]==0)
        {
            p[tmp]=1;
            ans++;
        }
    }
    if(ans==n)puts("YES\n");
    else puts("NO\n");
}