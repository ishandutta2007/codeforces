#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<bitset>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
long long n,m,ans;
char p[1000];
int map[10000];
void get_answer(long long a,long long b)
{
    ans+=a/b;
    if (a%b!=0)
    {
        get_answer(b,a%b);
    }
}
int main()
{
    cin>>n>>m;
    get_answer(n,m);
    cout<<ans<<endl;
    return 0;
}