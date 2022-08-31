#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<std::vector<long long>> vvll;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  
  int m,n,t,p;


  std::string s1,s2;
  cin>>s1;
  cin>>s2;
  vi a(s1.length(), 0);
  vi b(s2.length(), 0);
  for(int i=0; i <s1.length(); i++) a[i]=s1[i]-'0';
  for(int i=0; i <s2.length(); i++) b[i]=s2[i]-'0';

  int c1=0, c2=0;
  while(1){
	while((c1<s1.length())&&(a[c1]==0)) c1++;
	while((c2<s2.length())&&(b[c2]==0)) c2++;
	int l1=s1.length()-c1;
	int l2=s2.length()-c2;
	if((l1==0)){
		if(l2==0){
			cout<<"=";
			return 0;
		}
		cout<<"<";
		return 0;
	}
	if(l2==0){
		cout<<">";
		return 0;
	}
	if(l1==l2){
		  c1++;
		  c2++;
		  continue;
	}
	if(l1>l2+1){
		cout<<">";
		return 0;
	}
	if(l2>l1+1){
		cout<<"<";
		return 0;
	}
	if(l1==(l2+1)){
		if(l2==1){
			cout<<">";
			return 0;
		}
		if(b[c2+1]==1){
			c1++;
			c2+=2;
			continue;
		}
		else{
			if((a[c1+1]==1)||(a[c1+2]==1)){
				cout<<">";
				return 0;
			}
			a[c1+2]=1;
			c1+=2;
			c2++;
		}

	}
	if(l2==(l1+1)){
		if(l1==1){
			cout<<"<";
			return 0;
		}
		if(a[c1+1]==1){
			c2++;
			c1+=2;
			continue;
		}
		else{
			if((b[c2+1]==1)||(b[c2+2]==1)){
				cout<<"<";
				return 0;
			}
			b[c2+2]=1;
			c2+=2;
			c1++;
		}

	}


  }

  
  return 0;
}