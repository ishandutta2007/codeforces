t = int(input())

for _ in range(t):
    n = int(input())
    s = input()
    
    occ = [1] + [0] * n
    greater = [1, 0, 0]
    
    balance, answer = 0, 0
    for c in s:
        if c == '+':
            greater[balance % 3] -= occ[balance]
            balance += 1
            occ[balance] += 1
            greater[balance % 3] += 1
        else:
            balance -= 1
            occ[balance] += 1
            greater[balance % 3] += occ[balance]
        answer += greater[balance % 3] - 1
    
    print(answer)