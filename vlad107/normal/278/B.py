n=int(input())
s,t=[raw_input() for i in range(n)],[]
for i in range(n):
    for j in range(len(s[i])):
        for k in range(j,len(s[i])):t+=[s[i][j:k+1]]
f=lambda x:['',chr(96+x)][x!=0]
for i in range(27):
    for j in range(27):
        for k in range(1,27):
            q=f(i)+f(j)+f(k)
            if (q not in t):
                print q
                exit(0)