input()
s=input()
n=len(s)
a=['a', 'e', 'u', 'i', 'o', 'y']
k=1
for i in range(1, n):
    if s[i]==s[i-1] and s[i] in a:
        k+=1;
    else:
        print(s[i-1], end='')
        if k==2 and (s[i-1]=='o' or s[i-1]=='e'):
            print(s[i-1], end='')
        k=1
print(s[n-1], end='')
if k==2 and (s[i-1]=='o' or s[i-1]=='e'):
    print(s[n-1], end='')