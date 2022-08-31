#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <stack>

using namespace std;
char inp[200005];
char A[100005];
int main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  scanf("%s",A);
  int exists[26];
  memset(exists,0,26*4);
  for(int x=0;x<k;x++)
  {
    A[x]-='a';
    exists[A[x]]=1;
  }
  while(n--)
  {
    scanf("%s",inp);
    int len=strlen(inp);
    int nearest[len];
    int nearestOccurence[26];
    memset(nearestOccurence,127,26<<2);
    memset(nearest,127,len<<2);
    for(int x=0;x<len;x++)
    {
      inp[x]-='a';
      if(x<k)
	nearestOccurence[A[x]]=x;
      nearest[x]=abs(x-nearestOccurence[inp[x]]);
    }
    memset(nearestOccurence,127,26<<2);
    long long ANS=0;
    for(int x=k-1;x>=0;x--)
    {
      nearestOccurence[A[x]]=x;
      if(x>=len)continue;
//       printf("%d %d\n",nearest[x],ANS);
      nearest[x]=min(abs(x-nearestOccurence[inp[x]]),nearest[x]);
//       printf("%d %d\n",nearest[x],ANS);
    }
    for(int x=0;x<len;x++)
    {
      if(nearest[x]>1000000)nearest[x]=len;
      ANS+=nearest[x];
    }
    cout<<ANS<<"\n";
  }
}