n=input()
a=map(int,raw_input().split())
z=0
for i in range(1,n):
    if a[i-1]>a[i]:
            z=i
print z