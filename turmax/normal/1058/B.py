n,d=map(int,input().split())
c=int(input())
for i in range(c):
    x,y=map(int,input().split())
    if(x+y>=d and x+y<=2*n-d and -d<=x-y<=d):
        print("YES")
    else:
        print("NO")