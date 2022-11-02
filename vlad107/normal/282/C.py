a=raw_input()
b=raw_input()
print ["NO","YES"][(len(a)==len(b))&(not((a.count("1")>0)^(b.count("1")>0)))]