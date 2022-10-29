n, t = map(int,input().split())
s = input()
for i in range(t):
    j = 0
    while(j<len(s)-1):
        if(s[j]=='B')and(s[j+1]=='G'):
            s = s[:j]+'GB'+s[j+2:]
            j += 1
        j += 1
print(s)