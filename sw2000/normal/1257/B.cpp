#include<bits/stdc++.h>
using namespace std;

void f()
{
    int a,b;
    scanf("%d%d",&a,&b);
    if(a==1)
    {
        if(b==1)puts("yes");
        else puts("no");
        return;
    }
    if(a<=3)
    {
        if(b<=3)puts("yes");
        else puts("no");
        return;
    }
    puts("yes");
}

int main()
{
    //freopen("in.txt","r",stdin);
	int t;
	cin>>t;
	while(t--)
    {
        f();
    }
	return 0;
}