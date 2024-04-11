//
//  main.cpp
//  Round 483
//
//  Created by  on 2018/5/15.
//  Copyright  2018 . All rights reserved.
//

#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

struct dat{
	int a,b,c,d,e,f;
	bool operator == (const dat &rhs) const{
		return f == rhs.f &&  a == rhs.a && b == rhs.b && c == rhs.c && d == rhs.d && e == rhs.e;
	}
};

vector<pair<dat,int>> hmap[200010];

int query(dat x){
	unsigned int hsh = (((((x.a*11+x.b)*11+x.c)*11+x.d)*11+x.e)*19260817+x.f)%199999;
	hsh%=199999;
	for(int i=0;i<hmap[hsh].size();i++){
		if(hmap[hsh][i].first == x)return hmap[hsh][i].second;
	}
	return -1;
}
void change(dat x,int y){
	unsigned int hsh = (((((x.a*11+x.b)*11+x.c)*11+x.d)*11+x.e)*19260817+x.f)%199999;
	hsh%=199999;
	for(int i=0;i<hmap[hsh].size();i++){
		if(hmap[hsh][i].first == x){
			hmap[hsh][i].second = min(hmap[hsh][i].second,y);
			return;
		}
	}
	hmap[hsh].push_back(make_pair(x, y));
}

int n,cur;
int q,l[2020],r[2020];
int main() {
	cin>>n;
	change((dat){10,10,10,10,1,0},0);
	for(int i=0;i<=n;i++){
		for(int a = 1;a<10;a++)for(int b = a;b<10;b++)
		for(int c = b;c<10;c++)for(int d = c;d<10;d++)
		for(int e = 1;e<=9;e++){
			cur = query((dat){a,b,c,d,e,i});
			if(cur == -1)continue;
			change((dat){b,c,d,10,a,i},cur+abs(a-e)+1);
			change((dat){a,b,c,10,d,i},cur+abs(d-e)+1);
			change((dat){a,c,d,10,b,i},cur+abs(b-e)+1);
			change((dat){a,b,d,10,c,i},cur+abs(c-e)+1);
		}
		for(int a = 1;a<10;a++)for(int b = a;b<10;b++)
		for(int c = b;c<10;c++)for(int e = 1;e<=9;e++){
			cur = query((dat){a,b,c,10,e,i});
			if(cur == -1)continue;
			change((dat){a,b,10,10,c,i},cur+abs(c-e)+1);
			change((dat){a,c,10,10,b,i},cur+abs(b-e)+1);
			change((dat){b,c,10,10,a,i},cur+abs(a-e)+1);
		}
		for(int a = 1;a<10;a++)for(int b = a;b<10;b++)for(int e = 1;e<=9;e++){
			cur = query((dat){a,b,10,10,e,i});
			if(cur == -1)continue;
			change((dat){a,10,10,10,b,i},cur+abs(b-e)+1);
			change((dat){b,10,10,10,a,i},cur+abs(a-e)+1);
		}
		for(int a = 1;a<10;a++)for(int e = 1;e<=9;e++){
			cur = query((dat){a,10,10,10,e,i});
			if(cur == -1)continue;
			change((dat){10,10,10,10,a,i},cur+abs(a-e)+1);
		}
		if(i == n){
			int ans = 999999;
			for(int e = 1;e<=9;e++){
				cur = query((dat){10,10,10,10,e,i});
				if(cur == -1)continue;
				ans = min(ans,cur);
			}
			cout<<ans<<endl;
			return 0;
		}
		cin>>l[i]>>r[i];
		for(int e = 1;e<=9;e++){
			cur = query((dat){10,10,10,10,e,i});
			if(cur == -1)continue;
			change((dat){r[i],10,10,10,l[i],i+1},cur+abs(l[i]-e)+1);
		}
		for(int a = 1;a<10;a++)for(int b = a;b<10;b++)
		for(int c = b;c<10;c++)for(int e = 1;e<=9;e++){
			cur = query((dat){a,b,c,10,e,i});
			if(cur == -1)continue;
			int so[4];
			so[0] = a;so[1] = b;so[2] = c;so[3] = r[i];
			sort(so,so+4);
			change((dat){so[0],so[1],so[2],so[3],l[i],i+1},cur+abs(l[i]-e)+1);
		}
		for(int a = 1;a<10;a++)for(int b = a;b<10;b++)for(int e = 1;e<=9;e++){
			cur = query((dat){a,b,10,10,e,i});
			if(cur == -1)continue;
			int so[4];
			so[0] = a;so[1] = b;so[2] = 10;so[3] = r[i];
			sort(so,so+4);
			change((dat){so[0],so[1],so[2],so[3],l[i],i+1},cur+abs(l[i]-e)+1);
		}
		for(int a = 1;a<10;a++)for(int e = 1;e<=9;e++){
			cur = query((dat){a,10,10,10,e,i});
			if(cur == -1)continue;
			int so[4];
			so[0] = a;so[1] = 10;so[2] = 10;so[3] = r[i];
			sort(so,so+4);
			change((dat){so[0],so[1],so[2],so[3],l[i],i+1},cur+abs(l[i]-e)+1);
		}
	}
	return 0;
}