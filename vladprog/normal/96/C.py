from math import*

a=[list(input().lower()) for i in range(int(input()))]
s=input()
s0=list(s)
s=list(s.lower())
c=input()
C=chr(ord(c)-ord('a')+ord('A'))
r=['.']*len(s)
for t in a:
    for i in range(len(s)-len(t)+1):
        #print(s[i:i+len(t)],t)
        if(s[i:i+len(t)]==t):
            r[i:i+len(t)]=t
s=s0
for i in range(len(s)):
    if r[i]!='.':
        if ord(s[i])<=ord('Z'):
            if s[i]==C:
                if C=='A':
                    s[i]='B'
                else:
                    s[i]='A'
            else:
                s[i]=C
        else:
            if s[i]==c:
                if c=='a':
                    s[i]='b'
                else:
                    s[i]='a'
            else:
                s[i]=c
print(*s,sep='')