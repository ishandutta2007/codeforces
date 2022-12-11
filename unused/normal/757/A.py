cnt=[0]*256
for ch in raw_input():
    cnt[ord(ch)]+=1
print min([cnt[ord(ch)] for ch in 'bsrlB'] + [cnt[ord(ch)]/2 for ch in 'ua'])