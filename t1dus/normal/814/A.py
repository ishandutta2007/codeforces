# int(input())
# map(int,input().split())
# list(map(int,input().split()))
# for _ in range(int(input())):

n,m = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
b.sort(reverse = True)

c1 = 0
for i in range(n):
    if a[i] == 0:
        a[i] = b[c1]
        c1 += 1

for i in range(1,n):
    if a[i] <= a[i-1]:
        print("Yes")
        break
else:
    print("No")