import std.stdio;
import std.algorithm;

void main() {
	int N,M,i,j,a,b;
	readf(" %d %d %d %d %d %d",&N,&M,&i,&j,&a,&b);
	int ans =max(N,M)+1;
	if((i-1)%a == 0 && (j-1)%b == 0) {
		int x =(i-1)/a, y =(j-1)/b;
		if((x-y)%2 == 0 && N/a > 1 && M/b > 1) ans =min(ans,max(x,y));
		else if(x == 0 && y == 0) ans =0;}
	if((N-i)%a == 0 && (j-1)%b == 0) {
		int x =(N-i)/a, y =(j-1)/b;
		if((x-y)%2 == 0 && N/a > 1 && M/b > 1) ans =min(ans,max(x,y));
		else if(x == 0 && y == 0) ans =0;}
	if((i-1)%a == 0 && (M-j)%b == 0) {
		int x =(i-1)/a, y =(M-j)/b;
		if((x-y)%2 == 0 && N/a > 1 && M/b > 1) ans =min(ans,max(x,y));
		else if(x == 0 && y == 0) ans =0;}
	if((N-i)%a == 0 && (M-j)%b == 0) {
		int x =(N-i)/a, y =(M-j)/b;
		if((x-y)%2 == 0 && N/a > 1 && M/b > 1) ans =min(ans,max(x,y));
		else if(x == 0 && y == 0) ans =0;}
	if(ans <= max(N,M)) writeln(ans);
	else writeln("Poor Inna and pony!");}