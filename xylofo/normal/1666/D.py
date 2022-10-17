def solve():
    s,r = input().split()
    vis = set()
    last = len(s)-1
    done = 0
    for i in range(len(r)-1,-1,-1):
        for j in range(last,-1,-1):
            if s[j]==r[i]:
                if s[j] in vis:
                    print('NO')
                    return
                last=j-1
                done+=1
                break
            vis.add(s[j])
    if done==len(r):
        print('YES')
    else:
        print('NO')

t = int(input())
for _ in range(t):
    solve()