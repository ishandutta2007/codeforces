a=int(input())
b=sum([int(i) for i in input().split()])
c=sum([int(j) for j in input().split()])
if(c>b):
    print("No")
else:
    print("Yes")