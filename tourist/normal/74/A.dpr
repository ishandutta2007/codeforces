{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  tt,qq,x,y,a,b,c,d,e,cur,max: longint;
  ch: char;
  nam,ans: ansistring;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(tt);
  max:=-maxlongint;
  ans:='';
  for qq:=1 to tt do
  begin
    read(ch);
    while not (ch in ['a'..'z','A'..'Z','0'..'9','_']) do read(ch);
    nam:='';
    while ch in ['a'..'z','A'..'Z','0'..'9','_'] do
    begin
      nam:=nam+ch;
      read(ch);
    end;
    read(x,y,a,b,c,d,e);
    cur:=x*100-y*50+a+b+c+d+e;
    if cur > max then
    begin
      max:=cur;
      ans:=nam;
    end;
  end;
  writeln(ans);
  close(input);
  close(output);
end.