n = int(input())
l = sorted(abs(int(a)) for a in input().split())
j = 0
answer = 0
for i, a in enumerate(l):
    while j < n - 1 and l[j + 1] <= (a << 1):
        j += 1
    answer += j - i
print(answer)