S = "1*"+input()+"*1"
n = len(S)
ans = eval(S)
for i in range(2,n+1,2):
    if S[i-1]=='*':
        for j in range(i+1,n,2):
            if S[j]=='*':
                T = S[0:i]+'('+S[i:j]+')'+S[j:]
                ans = max(ans,eval(T))
print(ans)