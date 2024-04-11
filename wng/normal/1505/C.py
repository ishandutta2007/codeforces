s=input()

alph="ABCDEFGHIJKLMNOPQRSTUVWXYZ"

da=dict(zip(alph, range(26)))

#print(da)
isok=True
for i in range(2, len(s)):
    if da[s[i]]!=(da[s[i-1]]+da[s[i-2]])%26:
        #print(s[i-2:i+1], da[s[i]],da[s[i-1]],da[s[i-2]])
        isok=False

if isok:
    print("YES")
else:
    print("NO")