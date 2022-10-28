t = int(input())
for i in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    m = max(l)
    a = (sum(l)-m)/(len(l)-1)
    print(m+a)