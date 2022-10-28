t=int(input())
for i in range(t):
    s=input()
    if s==s[::-1]:
        a=len(s)
        done=False
        for j in range(a-1):
            if s[j]!=s[j+1]:
                print(s[:j]+s[j+1]+s[j]+s[j+2:])
                done=True
                break
        if not done:
            print(-1)
    else:
        print(s)