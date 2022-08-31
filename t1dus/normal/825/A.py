n = int(input())
s = input()
ans = []
cur = 0
for i in range(n):
    if s[i] == '1':
        cur += 1
    else:
        ans.append(cur)
        cur = 0
ans.append(cur)        
for i in ans:
    print(i,end='')