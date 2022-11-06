s=input()

nba=len([k for k in s if k=="a"])

res = nba+min(nba-1,len(s)-nba)

print(res)