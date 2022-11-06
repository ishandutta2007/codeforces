t=int(raw_input())
letters="abcdefghijklmnopqrstuvwxyz"
for i in range(t):
    n,m=[int(k) for k in raw_input().split()]
    print (letters[:m])*(n/m)+letters[:n%m]