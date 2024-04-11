#include <bits/stdc++.h>
using namespace std;

const int n = 1e5 + 5;
int N;
bool vis[10][10];

void move(int y, int x){
	vis[y][x] = true;
	char r = 'a'+x;
	cout << " " << r << (y+1);
}

void moveLast(int x, int n){
	if(n > 1){
		if(x == 0)
			x = 1;
		else
			x = 0;
		move(7, x);
		n--;
	}
	for(int i=8-n; i<8; i++){
		move(7, i);
	}
}

int makeComp(int y, int x, int rows){
	if(rows == 0)
		return x;
	for(int i=2; i<8; i++){
		x = i;
		move(y, x);
	}
	if(vis[y][0]){
		x = 1;
	}
	else{
		x = 0;
	}
	move(y, x);
	move(y+1, x);
	return makeComp(y+1, x, rows-1);
}

int main(){
	cin >> N;
	vis[0][0] = true;
	cout << "a1";
	if(N < 8){
		move(7, 0);
		for(int i=7-N+2; i<8; i++){
			move(7, i);
		}
		cout << endl;
		return 0;
	}
	int cury=0, curx=0;
	int complRow = (N-2)/8;
	curx = makeComp(0, 0, complRow);
	cury = complRow;
	int left = N - complRow*8;
	if(left == 9){
		if(curx == 0){
			curx = 1;
			move(cury, curx);
		}
		else{
			curx = 0;
			move(cury, curx);
		}
	}
	if(cury != 7){
		cury = 7;
		move(cury, curx);
		moveLast(curx, min(7, left-1));
	}
	else{
		moveLast(curx, min(7, left));
	}
	cout << endl;

	return 0;
}