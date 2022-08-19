{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  tt,qq,n,z,i,u: longint;
  com,st,s1,s2: ansistring;
  s: array [0..11111] of ansistring;
  v: array [0..11111] of longint;

function gets():ansistring;
var
  ch: char;
begin
  read(ch);
  while not (ch in ['&','*','a'..'z']) do read(ch);
  st:='';
  while ch in ['&','*','a'..'z'] do
  begin
    st:=st+ch;
    read(ch);
  end;
  gets:=st;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(tt);
  n:=2;
  s[1]:='void';
  v[1]:=0;
  s[2]:='errtype';
  v[2]:=-1;
  for qq:=1 to tt do
  begin
    com:=gets();
    if com = 'typedef' then
    begin
      s1:=gets();
      s2:=gets();
      z:=0;
      while Pos('&',s1) <> 0 do
      begin
        dec(z);
        Delete(s1,Pos('&',s1),1);
      end;
      while Pos('*',s1) <> 0 do
      begin
        inc(z);
        Delete(s1,Pos('*',s1),1);
      end;
      u:=0;
      for i:=1 to n do
        if s1 = s[i] then u:=i;
      inc(n);
      s[n]:=s2;
      if u = 0 then v[n]:=-1 else
      if v[u] = -1 then v[n]:=-1 else
      begin
        v[n]:=v[u]+z;
        if v[n] < 0 then v[n]:=-1;
      end;
    end else
    begin
      s1:=gets();
      z:=0;
      while Pos('&',s1) <> 0 do
      begin
        dec(z);
        Delete(s1,Pos('&',s1),1);
      end;
      while Pos('*',s1) <> 0 do
      begin
        inc(z);
        Delete(s1,Pos('*',s1),1);
      end;
      u:=0;
      for i:=1 to n do
        if s1 = s[i] then u:=i;
      if u = 0 then writeln('errtype') else
      if (v[u] = -1) or (v[u]+z < 0) then writeln('errtype') else
      begin
        write('void');
        for i:=1 to v[u]+z do write('*');
        writeln;
      end;
    end;
  end;
  close(input);
  close(output);
end.