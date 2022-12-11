n, x = map(int, input().split())

ans = [0]

for i in range(1, 2 ** n) : 
    if ((i ^ x) > i) :
        ans.append(i)

print(len(ans) - 1)
for i in range(1, len(ans)) :
    print(ans[i] ^ ans[i - 1], end = " ")