#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include<deque>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back

std::vector<std::string> alph;
class IAlphabet
{
public:
    virtual int encode(char symbol) = 0;
    virtual char decode(int code) = 0;
    virtual int size() = 0;
};

class alphabet_eng : public IAlphabet
{
public:
    virtual int encode(char symbol);
    virtual char decode(int code);
    virtual int size() {return 26;};
};
int alphabet_eng::encode(char symbol)
{
    if((symbol < 97) || (symbol >= 123)) return -1;
    else return (symbol - 97);
}

char alphabet_eng::decode(int code)
{
    if((code < 0) || (code >= 26)) return 0;
    else return(code + 97);
}

class VocabularyTrie
{
public:
    VocabularyTrie(IAlphabet & alphabet);
    VocabularyTrie(VocabularyTrie & parent);
    void Fill();
    int GetSize();
    bool m_end_of_word;
    IAlphabet & m_alphabet;
	int winner;
	int loser;

    std::vector<std::unique_ptr<VocabularyTrie>> m_children;
    VocabularyTrie* m_parent;
};

std::set<std::pair<int, VocabularyTrie*>> proce;
VocabularyTrie::VocabularyTrie(IAlphabet & alphabet):
    m_end_of_word(false),
    m_children(alphabet.size()),
    m_parent(nullptr),
    m_alphabet(alphabet)
{
	winner=2;
}

VocabularyTrie::VocabularyTrie(VocabularyTrie & parent):
    m_end_of_word(false),
    m_children(parent.GetSize()),
    m_parent(&parent),
    m_alphabet(parent.m_alphabet)
{

}

int VocabularyTrie::GetSize()
{
    return m_alphabet.size();
}

void VocabularyTrie::Fill()
{

    for(int i=0; i<alph.size(); i++)
    {
        std::string word;
        word=alph[i];
        VocabularyTrie* trie_ptr = this;
        for(int letter=0; letter<word.length(); letter++)
        {
            int curr_letter_code = m_alphabet.encode(word[letter]);

            if (trie_ptr->m_children[curr_letter_code]==nullptr)
            {
                trie_ptr->m_children[curr_letter_code].reset(new VocabularyTrie(*trie_ptr));
            }
            trie_ptr=trie_ptr->m_children[curr_letter_code].get();

        }
        trie_ptr->m_end_of_word=true;
		proce.insert(std::make_pair(word.length(),trie_ptr));
    }
}

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif

  int m,n,k;
  cin>>n>>k;
  for(int i=0;i<n;i++){
	  std::string x;
	  cin>>x;
	  alph.pb(x);
  }
  alphabet_eng alphabet;
  VocabularyTrie nn(alphabet);
  nn.Fill();
  
  while(proce.size()>=1){
	  //int x=proce.lower_bound(std::make_pair(100000, nullptr))->first;
	  //VocabularyTrie* y=proce.lower_bound(std::make_pair(100000, nullptr))->second;
	  auto h=proce.end();
	  h--;
	  int x=h->first;
	  VocabularyTrie* y=h->second;
	  proce.erase(std::make_pair(x,y));
	  int winner=2;
	  int loser=1;
	  for(int i=0; i<26; i++){
		  if(y->m_children[i]!=nullptr) loser=2;
	  }
	  if(y==nullptr) continue;
	  for(int i=0; i<26; i++){
		  if((y->m_children[i]!=nullptr)&&(y->m_children[i]->winner==2)) winner=1;
		  if((y->m_children[i]!=nullptr)&&(y->m_children[i]->loser==2)) loser=1;
		  
	  }
	  y->winner=winner;
	  y->loser=loser;
	  if(x>0) proce.insert(std::make_pair(x-1, y->m_parent));
  }
  int whowins=1;

  int u=nn.winner;
  int v=nn.loser;

  if(u==2) whowins=2;
  else{
	  if(v==1) whowins=1;
	  else whowins=2-(k%2);
	  
  }


  if(whowins==2) cout<<"Second";
  else cout<<"First";



  return 0;

}