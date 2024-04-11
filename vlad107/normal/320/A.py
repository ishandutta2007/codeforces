s=raw_input()
print ['NO','YES'][(max(len(t) for t in s.split('1'))<3)and(s[0]=='1')and(s.count('1')+s.count('4')==len(s))]