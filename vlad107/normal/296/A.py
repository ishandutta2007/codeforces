n=input()
a=map(int,raw_input().split())
print ["NO","YES"][max([a.count(i) for i in set(a)])<=(n+1)/2]