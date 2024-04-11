input()
for x in list(map(int,input().split())):
    if x%2==0:
        x-=1
    print(x,end=' ')