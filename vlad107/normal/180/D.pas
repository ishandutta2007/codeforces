var
  ss,ch:char;
  s,t:ansistring;
  last,i,j:longint;
  bad:boolean;
  kch:array['a'..'z']of longint;

begin
  readln(s);
  readln(t);
  fillchar(kch,sizeof(kch),$0);
  for i:=1 to length(s)do inc(kch[s[i]]);
  last:=-1;
  for i:=0 to length(t)do begin
    if (i>length(s))then break;
    if (i>0)then dec(kch[t[i]]);
    bad:=false;
    for ch:='a' to 'z' do 
      if (kch[ch]<0)then begin
        bad:=true;
        break;
      end;    
    if (bad)then break;
    bad:=true;
    if (i<length(t))
      then ss:=chr(ord(t[i+1])+1)
      else ss:=chr(ord('a')-1);
    for ch:=ss to 'z' do 
      if (kch[ch]>0)then begin
        bad:=false;
        break;
      end;
    if (bad)then continue;
    last:=i;
  end;
  if (last=-1)then begin
    writeln(-1);
    exit;
  end;  
  fillchar(kch,sizeof(kch),$0);
  for i:=1 to length(s)do inc(kch[s[i]]);
  write(copy(t,1,last));
  for i:=1 to last do dec(kch[t[i]]);
  if (last<length(t))
    then ss:=chr(ord(t[last+1])+1)
    else ss:=chr(ord('a')-1);
  for ch:=ss to 'z' do 
    if (kch[ch]>0)then begin
      write(ch);
      dec(kch[ch]);
      break;
    end;
  for ch:='a' to 'z'do
    for i:=1 to kch[ch] do write(ch);
  writeln;     
end.