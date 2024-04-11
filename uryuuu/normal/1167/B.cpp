#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
using namespace std;
int a[10]={4,8,15,16,23,42},d[5];
int main() {
    for(int i=1;i<=4;i++)
    {
        printf("? %d %d\n",i,i+1);
        cin>>d[i];
    }
    do
    {
        if(a[1]*a[0]==d[1]&&a[2]*a[1]==d[2]&&a[3]*a[2]==d[3]&&a[4]*a[3]==d[4])
            break;
    }while(next_permutation(a,a+6));
    printf("!");
    
    for(int i=0;i<6;i++)
        cout<<" "<<a[i];
    return 0;
}