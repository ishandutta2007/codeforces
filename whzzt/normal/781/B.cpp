#include "bits/stdc++.h"

using namespace std;

const int N = 1005;

char s1[N][25],s2[N][25];
int n,style[26][26];

vector<int> e[26][26];
int vis[2][26];

int main(){
	cin>>n;
	for (int i = 1; i <= n; i ++){
		scanf("%s", s1[i]), scanf ("%s", s2[i]);
		e[s1[i][0]-'A'][s1[i][1]-'A'].push_back(i);
	}
	
	for (int i = 0; i < 26; i ++){
		for (int j = 0; j < 26; j ++){
			memset (vis, 0, sizeof(vis));
			for (int k = 0; k < e[i][j].size(); k ++){
				int t = e[i][j][k];
				vis[0][s1[t][2]-'A'] ++;
				vis[1][s2[t][0]-'A'] ++;
			}
			bool flag1 = true, flag2 = true;
			for (int k = 0; k < 26; k ++){
				if (vis[0][k] > 1) flag1 = false;
				if (vis[1][k] > 1) flag2 = false;
			}
			if (flag1 || flag2){
				if (flag1) style[i][j] = 1;
				else style[i][j] = 2;
			} else {puts ("NO"); exit(0);}
		}
	}
	
	puts ("YES");
	for (int i = 1; i <= n; i ++)
		putchar (s1[i][0]), putchar(s1[i][1]),
		putchar (style[s1[i][0]-'A'][s1[i][1]-'A'] == 1 ? s1[i][2] : s2[i][0]),
		putchar ('\n');
		
				
	return 0;
}