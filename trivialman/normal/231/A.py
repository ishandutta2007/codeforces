n = int(input())
cnt = 0
for i in range(n):
    x,y,z=list(map(int, input().split()))
    if(x+y+z>=2):
        cnt+=1
print(cnt)