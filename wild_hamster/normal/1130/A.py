n = (int(input()) +1)//2 - 1
a = list(map(int, input().split()))
x = sum((1 if i > 0 else 0) for i in a)
y = sum((1 if i < 0 else 0) for i in a)
print(-1 if y > n else (1 if x > n else 0))