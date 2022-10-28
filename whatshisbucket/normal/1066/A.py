a=int(input())
for i in range(a):
    b=list(map(int,input().split()))
    lanterns=b[0]//b[1]
    c=b[2]%b[1]
    lanterns-=(b[3]-b[2]+c)//b[1]
    if b[2]%b[1]==0:
        lanterns-=1
    print(lanterns)