t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    answer = 0
    for i in range(n):
        sum = 0
        for j in range(i, n):
            sum += -1 if s[j] == '-' else 1
            answer += 1 if sum % 3 == 0 and sum <= 0 else 0
    print(answer)