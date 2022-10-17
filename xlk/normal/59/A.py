s=raw_input()
print[s.lower(),s.upper()][sum(map(str.isupper,s))>len(s)/2]