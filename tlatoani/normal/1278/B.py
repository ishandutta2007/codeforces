t=int(input())
while t:
 t-=1;a,b=map(int,input().split());r=1
 while(r-1)*r<abs(a-b)*2or(r//2-a+b)%2:r+=1
 print(r-1)