n=input()
s=raw_input()
print(['YES\n'+('('+s[:-2].replace(' ','->(')+')'*(n-1)+'->')*(n>1)+'0','NO'][s[-1]=='1' or s=='1 '*(n-2)+'0 0'])