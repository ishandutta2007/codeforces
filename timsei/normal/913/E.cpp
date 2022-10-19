#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

string Fo;

int n , m;

int x , y , z;

bool cmp (string xxx , string yyy) {
    if(xxx.length() == yyy.length()) return xxx < yyy;
    return xxx.length() < yyy.length();
}

struct NODE {
    string cur;
    int mask , pri;
    friend bool operator < (NODE xxx , NODE yyy) {
	return (xxx.cur.length() == yyy.cur.length()) ? xxx.cur > yyy.cur : xxx.cur.length() > yyy.cur.length();
    }
    void init(void) {
	cur = ""; mask = 0; pri = 4;
    }
    friend NODE operator | (NODE xxx , NODE yyy) {
	NODE ret;
	if(xxx.cur > yyy.cur) swap(xxx , yyy);
	ret.cur = xxx.cur + "|" + yyy.cur;
	ret.mask = xxx.mask | yyy.mask;
	ret.pri = 1;
	return ret;
    }
    friend NODE operator & (NODE xxx , NODE yyy) {
	NODE ret;
	if(xxx.cur > yyy.cur) swap(xxx , yyy);
	ret.cur = xxx.cur + "&" + yyy.cur;
	ret.mask = xxx.mask & yyy.mask;
	ret.pri = 2;
	return ret;
    }
    friend NODE operator !(NODE xxx) {
	NODE ret;
	ret.cur = "!" + xxx.cur;
	ret.mask = 255 - xxx.mask;
	ret.pri = 3;
	return ret;
    }
    NODE addpar(NODE xxx) {
	xxx.pri = 4;
	xxx.cur = "(" + xxx.cur + ")";
	return xxx;
    }
} dp[N][5] ;

bool vis[N][5];

string ans[N];

priority_queue<NODE>q;

vector<NODE>that;

void predance(void) {
    dp[x][4].init(); dp[y][4].init(); dp[z][4].init();
    dp[x][4].cur = "x"; dp[y][4].cur = "y"; dp[z][4].cur = "z";
    dp[x][4].mask = x; dp[y][4].mask = y; dp[z][4].mask = z;
    q.push(dp[x][4]); q.push(dp[y][4]); q.push(dp[z][4]);
    while(!q.empty()) {
	while(vis[q.top().mask][q.top().pri] && !q.empty()) q.pop();
	if(q.empty()) break;
	NODE T = q.top(); that.push_back(T); q.pop();
	if(T.pri >= 1) {
	    for(int i = 0;i < (int)that.size();++ i) {
		NODE now = T | that[i];
		if(!vis[now.mask][now.pri]) q.push(now);
	    }
	}
	if(T.pri >= 2) {
	    for(int i = 0;i < (int)that.size();++ i) if(that[i].pri>=2){
		NODE now = T & that[i];
		if(!vis[now.mask][now.pri]) q.push(now);
	    }
	}
	if(T.pri >= 3) {
	    NODE now = !T;
	    if(!vis[now.mask][now.pri]) q.push(now);
	}
	NODE now = T.addpar(T);
	if(!vis[now.mask][now.pri]) q.push(now);
	vis[T.mask][T.pri] = 1;
	dp[T.mask][T.pri] = T;
    }
}

void dance(string fight) {
    int mask = 0;
    for(int i = 0;i < 8;++ i) if(fight[i] == '1') mask += (1 << i);
    cout << ans[mask] << endl;
}

int main(void) {
    scanf("%d" , &n);
    for(int i = 0;i < 8;++ i) x += (i / 4) * (1 << i) , y += (i / 2) % 2 * (1 << i) , z += (i % 2) * (1 << i);
    predance();
    for(int i = 0;i < 256;++ i) {
	ans[i] ="&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*adhsajhkjsdaasdasdjlkajsdljasdljalkdjslakjdalkdjlaksjdalkdsjlaksdjlaksdjlakdjlakjdlajsdlkajsdalkjdslajsdlkajsdlkajskdlja";
	for(int j = 1;j <= 4;++ j) if(vis[i][j]) {
	    if(cmp(dp[i][j].cur , ans[i])) ans[i] = dp[i][j].cur;
	}
    }
    for(int i = 1;i <= n;++ i) cin >> Fo , dance(Fo);
}