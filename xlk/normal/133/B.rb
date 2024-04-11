s=gets
s=s.gsub '>','1000'
s=s.gsub '<','1001'
s=s.gsub '+','1010'
s=s.gsub '-','1011'
s=s.gsub '.','1100'
s=s.gsub ',','1101'
s=s.gsub '[','1110'
s=s.gsub ']','1111'
p s.to_i(2)%1000003