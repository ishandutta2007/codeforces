inp =input().split()
N =int(inp[0])
A =int(inp[1])
B =int(inp[2])

ans =[2 for i in range(N)]
x =input().split()
for i in x: ans[int(i)-1] =1

for i in ans: print(i)