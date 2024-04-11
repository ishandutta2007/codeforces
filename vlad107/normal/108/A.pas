{$r-,q-,s-,i-,o+}
var
  tt,hh,mm:longint;
  s,ms,hs:string;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  readln(s);
  hh:=(ord(s[1])-48)*10+ord(s[2])-48;
  mm:=(ord(s[4])-48)*10+ord(s[5])-48;
  tt:=hh*60+mm;
  while (tt<1439)do begin 
    inc(tt);
    hh:=tt div 60;
    mm:=tt mod 60;
    str(hh,hs);
    if (length(hs)=1)then hs:='0'+hs;
    str(mm,ms);
    if (length(ms)=1)then ms:='0'+ms;
    if (hs[1]=ms[2])and(hs[2]=ms[1])then begin
      writeln(hs,':',ms);
      exit;
    end;
  end;
  writeln('00:00');
  close(output);close(input);
end.