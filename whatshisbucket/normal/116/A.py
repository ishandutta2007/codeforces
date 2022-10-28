n=int(input())
max=0
current=0
for i in range(n):
    a,b=map(int,input().split())
    current+=(b-a)
    if current>max:
        max=current
print(max)