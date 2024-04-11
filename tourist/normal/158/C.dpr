{$R-,S-,Q-,I-,O+}
var
  n,q,i,j: longint;
  s,t,w: string;

procedure get(var t:string);
var
  ch: char;
begin
  read(ch);
  while not (ch in ['a'..'z','.','/']) do read(ch);
  t:='';
  while ch in ['a'..'z','.','/'] do
  begin
    t:=t+ch;
    read(ch);
  end;
end;

begin
  readln(n);
  s:='/';
  for q:=1 to n do
  begin
    get(t);
    if t = 'pwd' then writeln(s) else
    begin
      get(t);
      if t[1] = '/' then
      begin
        s:='/';
        Delete(t,1,1);
      end;
      if t = '' then continue;
      t:=t+'/';
      w:='';
      for i:=1 to length(t) do
        if t[i] <> '/' then w:=w+t[i] else
        begin
          if w = '..' then
          begin
            for j:=length(s)-1 downto 1 do
              if s[j] = '/' then
              begin
                Delete(s,j+1,length(s)-j);
                break;
              end;
          end
          else s:=s+w+'/';
          w:='';
        end;
    end;
  end;
end.