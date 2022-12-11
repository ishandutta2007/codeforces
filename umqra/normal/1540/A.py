def solve(values):
    if len(values) == 1: return 0
    values = sorted(values)
    result = values[-1]
    for i in range(len(values) - 1):
        result -= (values[i + 1] - values[i]) * (i + 1) * (len(values) - i - 1)
    return result
t = int(input())
for _ in range(t):
    input()
    values = list(map(int, input().split()))
    print(solve(values))