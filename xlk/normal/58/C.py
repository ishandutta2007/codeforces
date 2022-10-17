n=input();x=[n]*4**9;a=map(int,raw_input().split())
for i in range(n):x[a[i]-min(i,n-i-1)]-=1;
print min(x[1:])