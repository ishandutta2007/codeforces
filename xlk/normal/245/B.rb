gets
if /^(http|ftp)([a-z]+)ru([a-z]*)$/
	puts $1+'://'+$2+'.ru'+($3==''?'':'/'+$3)
end