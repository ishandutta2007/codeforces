n,s,r=int(input()),input(),range
print(['yes','no'][all('.'in s[i:i+5*j:j]for i in r(n-4)for j in r(1,(n-i+3)//4))])